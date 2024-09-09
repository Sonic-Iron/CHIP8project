#include <cstdint>
#include<array>
#include<string>
class chip8 {
private:
	//CPU 
	std::array<uint8_t, 16> VR;
	uint16_t I, PC;
	uint8_t sp;
	std::array<uint16_t, 16> stack;
	uint8_t delay_timer, sound_timer;

	//MEMORY
	std::array<uint8_t, 4096> memory;

	//DISPLAY

	std::array<bool, 64 * 32> display;

	//PERIPHERALS

	std::array<int, 16> keypad;

	//OTHER

	bool draw_flag;

	int get_nibble(int, int, int);

public:
	chip8();
	bool load_rom(std::string);
	bool get_draw_flag();
	void set_draw_flag();
	void single_cycle();

	bool get_display_value(int);
	void set_keypad_value(int, int);

	~chip8();


};