//
// Lightpad - Helpers.h
// ©2017 Nightwave Studios: Vinyl Darkscratch, Light Apacha, Origami1105, WhoovesPON3.
// Additional support from LaunchpadFun (http://www.launchpadfun.com/en/).
// https://www.nightwave.co/lightpad
//

// Enhencement by @DKingCN

#pragma once
#include <windows.h>
#include <algorithm>
#include "../rtmidi/RtMidi.h"
#include "../midifile/MidiFile.h"

#define MSG_FIN 256
#define SYSEX_FIN 247

int note_to_button(int note);
int button_to_note(int button);

class LaunchpadBase 
{
	public:
		LaunchpadBase();
		int connect();
		void disconnect();
		bool isConnected();
		int getMidiPort(std::string name, RtMidi* ports);
		double getMessage(std::vector<BYTE>* message_in);
        void sendMessage(unsigned int first_byte, ...);
		virtual void setColor(BYTE key, BYTE color);
		virtual void setPulse(BYTE key, BYTE color);
		std::string INPORT_NAME;
		std::string OUTPORT_NAME;
        std::string PRODUCT_NAME;
        int channel = 0;
	protected:
        HANDLE sendmessage_mutex;
		RtMidiIn* midiin;
		RtMidiOut* midiout;
		int inport = 0;
		int outport = 0;
		bool connected = false;
        int PadStatus[256] = {};
};

class LaunchpadPro : public LaunchpadBase
{
	public:
		LaunchpadPro();
		int connect();
		void disconnect();
		bool isConnected();
		void setColor(BYTE key, BYTE color);
		void setColor(BYTE key, BYTE red, BYTE green, BYTE blue);
        void setColor(int row, int col, int color);
        void setRowColor(int row, int color);
        void setColumnColor(int col, int color);
        void stopDisplayText();
        void setPadColor(int color);
        void clearPad();
		void setFlash(BYTE key, BYTE color);
        void setFlash(int row, int col, BYTE color);
		void setPulse(BYTE key, BYTE color);
        void setPulse(int row, int col, BYTE color);
		void displayText(unsigned int color, bool loop, unsigned int speed,  std::string text);
        void playMidiFile(std::string file);
        void playMidiFile_speed(std::string file, int speed);

    private:
        bool isButton(int row, int col);
        bool isKey(int row, int col);
        bool isButton(int code);
        bool isKey(int code);
        std::string game_to_map;

};
