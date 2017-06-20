#include <stdio.h>

// dmemの大きさ
#define MEM_SIZE 256
// 1行に表示するメモリの値の数
#define NUM_COLUMN 16
// dmem の状態を表示する際にメモリ1区画あたりが使う文字幅
// dmem の中身は16ビットで16進数4桁に対応するため+1して5とする
#define TAB_OF_MEM_STATE 5

#define ST(rs1, rs2) dmem[(rs1) % MEM_SIZE] = (rs2)
#define LD(rd, rs1) rd = dmem[(rs1) % MEM_SIZE]
#define ADD(rd, rs1, rs2) rd = (rs1) + (rs2)
#define LI(rd, imm) rd = (imm)
#define B(label) goto label
#define BNZ(rs1, label) if (rs1) goto label
#define MLT(rd, rs1, rs2) rd = (rs1) * (rs2)
#define CMP(rd, rs1, rs2) rd = (rs1 > rs2) ? -1 : 0
#define BZ(rs1, label) if (!(rs1)) goto label
#define ADDI(rd, rs1, imm) rd = rs1 + imm

short r0, r1, r2, r3, r4, r5, r6, r7;
short dmem[MEM_SIZE];

// レジスタの状態を表示する
void reg();
// dmemの状態を表示する
void mem();
// dmemの特定のアドレスの状態を表示する
void memAt(int address);

// 以下、mem()以外での呼び出し禁止
void printMemHeader();
void printMemState();

void reg() {
  printf("r0\tr1\tr2\tr3\tr4\tr5\tr6\tr7\n");
  printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
	 r0, r1, r2, r3, r4, r5, r6, r7);
}

void mem() {
  printMemHeader();
  printMemState();
}

void memAt(int address) {
  address = address % MEM_SIZE;
  printf("dmem[%2x]:%4x\n", address, dmem[address]);
}

void printMemHeader() {
  for (int i = 0; i < 3; ++i)
    printf(" ");
  printf("| ");
  for (int i = 0; i < NUM_COLUMN; ++i) 
    printf("%4x ", i);
  printf("\n");

  for (int i = 0; i < TAB_OF_MEM_STATE * (NUM_COLUMN + 1); ++i)
    printf("-");
  printf("\n");
}

void printMemState() {
  for (int row = 0; row < MEM_SIZE / NUM_COLUMN; ++row) {
    printf("%2x | ", row);
    for (int column = 0; column < NUM_COLUMN; ++column) {
      printf("%4x ", dmem[row * NUM_COLUMN + column]);
    }
    printf("\n");
  }
}
