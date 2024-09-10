#include <cstdint>
#include<array>
#include<string>
class chip8 {
	private:
		//CPU 
		std::array<uint8_t, 16> ViRe;
		std::array<uint16_t, 16> stack;
		uint16_t I, PC;
		uint8_t SP;
		uint8_t delay_timer, sound_timer;

		//MEMORY
		std::array<uint8_t, 4096> memory;

		//DISPLAY

		std::array<bool, 64 * 32> display;
		int V_WIDTH;

		//PERIPHERALS

		std::array<int, 16> keypad;

		//OTHER

		bool draw_flag;

	public:
		chip8();
		void load_rom(const std::string* rom_location);
		bool get_draw_flag();
		void set_draw_flag();
		void single_cycle();

		bool get_display_value(int display_location);
		~chip8();


};