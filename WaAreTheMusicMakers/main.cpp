#include "imgui-SFML.h"
#include "imgui.h"
#include "Sound.h"
#include"Convert.h"
#include"FileDialog.h"
#include "StructTrack.h"

#include <vector>
#include<string>
#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

PWSTR pszFilePath;
std::string str;

int main() {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "S");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    //Soundd sound;
    std::vector<Soundd> soundVec;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        if (ImGui::Button("Add sound", ImVec2(100, 100)))
        {
            ShowFileDialog(pszFilePath);
            ConvertWideCharToNative(pszFilePath, str);

            Soundd sound(str);
            soundVec.push_back(sound); //может создать класс с vec<soundd>? ДА upd: нет

        }
        if (ImGui::Button("Add sound", ImVec2(100, 300)))
        {
            //soundVec[1].Play();

        }

        std::vector<const char*> names =
        {
            "music 1", "music 2", "music 3",
            "music 4"
        };
        for (int n = 0; n < names.size(); n++)
        {
            ImGui::PushID(n);
            if ((n % 3) != 0)
                ImGui::SameLine();
            ImGui::Button(names[n], ImVec2(60, 60));
            
            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
            {
                
                ImGui::SetDragDropPayload(names[n], &n, sizeof(int));

                ImGui::EndDragDropSource();
            }
            if (ImGui::BeginDragDropTarget())
            {
                ImGui::EndDragDropTarget();
            }
      
            ImGui::PopID();
        }
        ImGui::BeginGroup();
        
        Track OneTrack;
        
        for (std::vector<const char*>::size_type n = 0; n != 1; n++) {
            ImVec2 positionPlus = ImGui::GetCursorPos();
            ImGui::Button(OneTrack.plus);
            //std::cout << positionPlus.x << " " << positionPlus.y << std::endl;
            ImGui::PushID(*OneTrack.plus);
            ImGui::SameLine();

            if (ImGui::BeginDragDropSource())
            {
                ImGui::EndDragDropSource();
            }

            if (ImGui::BeginDragDropTarget())
            {
                OneTrack.names.push_back(names[n]);
                OneTrack.number++; 

                ImGui::SetCursorPos(positionPlus);
                ImVec2 l(100, 10);
                ImGui::Button(OneTrack.names[n], l);
                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(names[n]))
                {
                    IM_ASSERT(payload->DataSize == sizeof(int));
                    int payload_n = *(const int*)payload->Data;

                    OneTrack.names[n] = names[payload_n];

                }
                positionPlus.x += l.x;
                ImGui::EndDragDropTarget();
            }
            
            ImGui::PopID();
        }
        ImGui::EndGroup();

        ImGui::ShowDemoWindow();

        window.clear(sf::Color::Black);
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
    return 0;
}

//Advapi32.lib
//sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();

