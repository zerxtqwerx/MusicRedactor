#pragma once

#include<SFML\Audio.hpp>
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include"FileDialog.h"

#include<string>
#include<memory>
#include<iostream>

class Soundd
{
	//класс дл€ каждого отдельного звука форматов (???)
	//нужно: 
	//поле звука, конструктор берет из его из файла пользовател€.
	//поле длительности по времени. обновл€етс€ с каждым добавлением нового саунда
public:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Sound* soundPtr;
	sf::Time duration;
	//можно добавить SamplRate, SampleCount

	Soundd(std::string& str) {
		//open in sound
		try {
			if (!buffer.loadFromFile(str)) {
				throw 1;
			}
		}
		catch(int thr) { std::cout << "Error " << thr << ": Soundd: load failed" << std::endl; }

		sound.setBuffer(buffer);
		soundPtr = &sound;
		duration = buffer.getDuration();
	}
	Soundd(const Soundd&); //copy
	//Soundd(Soundd&& other) noexcept; //move

	~Soundd() { }

	//Soundd& operator=(const Soundd& other);
	//Soundd& operator=(Soundd&& other) noexcept;
	//void Swap(Soundd& other) noexcept;

	void Play()
	{
		this->sound.play();
	}
};

Soundd::Soundd(const Soundd& other)
{
	this->buffer = other.buffer;
	this->sound = other.sound;
	this->soundPtr = other.soundPtr;
	this->duration = other.duration;
}

//void Soundd::Swap(Soundd& other) noexcept
//{
//	//добавить
//	std::swap(this->sound, other.sound);
//	std::swap(this->duration, other.duration);
//	std::swap(this->soundPtr, other.soundPtr);
//}
//
//Soundd& Soundd::operator=(const Soundd& other) //copy's consturctor
//{
//	Soundd tmp(other);
//	Swap(tmp);
//	return *this;
//}
//
//Soundd& Soundd::operator=(Soundd&& other) noexcept //move's constructor
//{
//	Soundd tmp(std::move(other));
//	Swap(other);
//	return *this;
//}

////TODO: /////
// 
//bool operator ( if() )


////Other/////

//this->sound.sf::Music::~Music(); (for ~Soundd)

//нужен конструктор копировани€ или контейнер с указател€ми в мэйн
// 
//¬џЅ»–јё  ќЌ—“–” “ќ–  ќѕ»–ќ¬јЌ»я!!!!!!!!!!!!

//apd: кажеца надо мен€ть music класс на uint64 и писать свое(pls no) upd: нет

//тек, либо убрать возможность подгружать звуки и встроить свою библиотеку(возможно, с поиском) <-выбираю это???
//либо подгружать файлы из окна диалога в рабочую папку проекта и присваивать экземпл€рам класса Soundd (i think no по причичне компил€ции)