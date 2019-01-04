#include <stdint.h>

//The CPU of the NES with 6 registers and 0x800 Byte of internal RAM
class CPU
{

public:
    //CPU Registers
    uint8_t A, X, Y;
    //Programm Counter
    uint16_t PC;
    //Stack Pointer
    uint8_t S;
    //Status Register
    uint8_t P;

    //Internal Ram of the NES
    uint8_t CPU_RAM[0x0800]{0};

    //=========PPU Registers(8Byte from 0x2000 to 0x2007) used for adressing the PPU==================
    //PPUCTRL       0x2000
    //PPUMASK	    0x2001	BGRs bMmG	color emphasis (BGR), sprite enable (s), background enable (b), sprite left column enable (M), background left column enable (m), greyscale (G)
    //PPUSTATUS	    0x2002	VSO- ----	vblank (V), sprite 0 hit (S), sprite overflow (O); read resets write pair for $2005/$2006
    //OAMADDR	    0x2003	aaaa aaaa	OAM read/write address
    //OAMDATA	    0x2004	dddd dddd	OAM data read/write
    //PPUSCROLL	    0x2005	xxxx xxxx	fine scroll position (two writes: X scroll, Y scroll)
    //PPUADDR	    0x2006	aaaa aaaa	PPU read/write address (two writes: most significant byte, least significant byte)
    //PPUDATA	    0x2007
    uint8_t PPU_REG[8];

    CPU();
    ~CPU();

    //  Is called each simulated CPU tick to perform the actions the
    //  CPU is supposed to be doing
    void tick();

    //Executes the correct instruction for the specific opcode
    void opcode(uint8_t code);
private:

    //Load
    void lda();
    void ldx();
    void ldy();

    //Store
    void sta();
    void stx();
    void sty();

    //Transfer
    void tax();
    void tay();
    void tsx();
    void txa();
    void txs();
    void tya();

    //Add with Carry
    void adc();

    //Decrement
    void dec();
    void dex();
    void dey();

    //Increment
    void inc();
    void inx();
    void iny();

    //Subtraction with borrow
    void sbc();

};

