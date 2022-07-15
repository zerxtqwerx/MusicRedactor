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
	//����� ��� ������� ���������� ����� �������� (???)
	//�����: 
	//���� �����, ����������� ����� �� ��� �� ����� ������������.
	//���� ������������ �� �������. ����������� � ������ ����������� ������ ������
public:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Sound* soundPtr;
	sf::Time duration;
	//����� �������� SamplRate, SampleCount

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
//	//��������
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

//����� ����������� ����������� ��� ��������� � ����������� � ����
// 
//������� ����������� �����������!!!!!!!!!!!!

//apd: ������ ���� ������ music ����� �� uint64 � ������ ����(pls no) upd: ���

//���, ���� ������ ����������� ���������� ����� � �������� ���� ����������(��������, � �������) <-������� ���???
//���� ���������� ����� �� ���� ������� � ������� ����� ������� � ����������� ����������� ������ Soundd (i think no �� �������� ����������)