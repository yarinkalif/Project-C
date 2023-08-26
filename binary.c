#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"
#include "utils.h"

/**
 * Represents the given assembly line instruction in binary format.
 * @param machineCode: The output binary representation of the instruction.
 * @param keyWord: Assembly instruction keyword (e.g., "MOV", "ADD").
 * @param operands: The operands for the instruction.
 * @param numberLine: The line number of the instruction in the assembly file.
 */
void line_instruction_binary(char *machineCode, char *keyWord, char *operands, int numberLine) {
	int currOpcode = 0;
	instructionGroup1 currLine1;
	instructionGroup2 currLine2;
	instructionGroup3 currLine3;

	int typeOfKeyWord = get_instruction_type(keyWord, &currOpcode);

	switch (typeOfKeyWord) {
		case 1:
			currLine1 = create_instruction_1(keyWord, operands, currOpcode, typeOfKeyWord, numberLine);
			int_to_binary(machineCode, currLine1.size.WORD);
			break;

		case 2:
			currLine2 = creat_instruction_2(keyWord, operands, currOpcode, typeOfKeyWord, numberLine);
			int_to_binary(machineCode, currLine2.size.WORD);
			break;
		case 3:
			currLine2 = create_instruction_3(keyWord, currOpcode, typeOfKeyWord, numberLine);
			int_to_binary(machineCode, currLine3.size.WORD);
}

/**
 * Identifies the type of the operand (e.g., REGISTER, NUMBER, STRING, LABEL).
 * @param operand: The operand string to identify.
 * @return: The type of operand.
 */
OperandType identify_operand_type(char *operand) {
    if (operand[0] == '@' && operand[1] == 'r' && operand[2] >= '0' && operand[2] <= '7' && operand[3] == '\0') {
        return REGISTER;
    } else if (isdigit(operand[0]) || (operand[0] == '-' && isdigit(operand[1]))) {
        return NUMBER;
    } else if (operand[0] == '"' && operand[strlen(operand) - 1] == '"') {
        return STRING;
    } else {
        return LABEL;
    }
}

/**
 * Creates the instruction for group 1, which involves two operands.
 * @param keyword: Assembly instruction keyword.
 * @param operands: The operands for the instruction.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 1 instruction.
 */
	instructionGroup1 create_instruction_1(char *keyword, char *operands, int currOpcode, int typeOfKeyWord, int numberLine) {
	instructionGroup1 instr;
	instr->instruction.opcode = currOpcode;

	char *operand1 = strtok((char *)operands, ",");
	char *operand2 = strtok(NULL, ",");

	if (!operand1 || !operand2) {
		printf("error: missing operand\n");
		instr.size = 0;
		return instr;
	}
	/*idenify the operand types*/
	operandType operand_1_type = identify_operand_type(operand1);
	operandType operand_2_type = identify_operand_type(operand2);

	switch (operand_1_type) {
		case REGISTER:
			instr.instruction.operandSrc = operand1[2] - '0'; /*convert int to char*/
			break;
		case LABEL:
			break;
		case STRING:
			instr.instruction.operandSrc = operand1;
			break;
		case NUMBER:
			instr.instruction.operandSrc = operand1;
			break;
	}
	switch (operand_2_type) {
		case REGISTER:
			instr.instruction.operandDst = operand1[2] - '0'; /*convert int to char*/
			break;
		case LABEL:
			break;
		case STRING:
			instr.instruction.operandDst = operand1;
			break;
		case NUMBER:
			instr.instruction.operandDst = operand1;
			break;
	}
	instr.instruction.str = 0;
	return instr;
}	

/**
 * Creates the instruction for group 2, which involves two operands.
 * @param keyword: Assembly instruction keyword.
 * @param operands: The operands for the instruction.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 2 instruction.
 */
	instructionGroup2 create_instruction_2(char *keyword, char *operands, int currOpcode, int typeOfKeyWord, int numberLine) {
	instructionGroup1 instr;
	instr->instruction.opcode = currOpcode;

	if (operands == NULL) {
		printf("error: missing operand\n");
		return instr;
	}
	operandType operand_type = identify_operand_type(operands);

	switch (operandType) { /*the source operand is always 0*/
		case REGISTER:
			instr.instruction.operandSrc = 0;
			instr.instruction.operandDst = operand1[2] - '0'; /*convert int to char*/
		case LABEL:
			break;
	}	
	instr.instruction.str = 0;	
}

/**
 * Creates the instruction for group 3, which doesn't involve operands.
 * @param keyword: Assembly instruction keyword.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 3 instruction.
 */	
instructionGroup3 create_instruction_3(char *keyword, int currOpcode, int typeOfKeyWord, int numberLine) {
	instructionGroup1 instr;
	instr->instruction.opcode = currOpcode;
	instr.instruction.operandSrc = 0; /*the source operand is always 0*/
	instr.instruction.operandDst = 0; /*the destination operand is always 0*/
	instr.instruction.str = 0;
}

/**
 * Represents the given assembly guidance in binary format.
 * @param machineCode: The output binary representation.
 * @param keyWord: Assembly guidance keyword (e.g., "DATA", "STRING").
 * @param dataList: The data for the guidance.
 * @param typeOfGuidence: The type of guidance.
 * @param numberLine: The line number of the guidance in the assembly file.
 */

void line_guidence_binary(char *machineCode, char *keyWord, long dataList,int typeOfGuidence, int numberLine) {
	DataCode currData; 
	DataCode currStr;

	switch(typeOfGuidence)
		case DATA:
			if (list > ....) {
				printf("error\n");
			}
			currData.guidence.word = dataList;
			int_to_binary(machineCode, currData.size, WORD);
			break;
		case STRING:
			if (list > ....) {
				printf("error\n");
			}
			currStr.guidence.word = currStr;
			int_to_binary(machineCode, currStr.size, WORD);	
			break;
	} /*end of switch*/	
}

/**
 * Converts the given integer into its binary representation.
 * @param machineCode: The output binary string.
 * @param curr: The integer to convert.
 * @param numOfBit: The number of bits in the integer.
 */
void int_to_binary(char *machineCode, int curr, int numOfBit) {
	unsigned mask = 1;

	for (; mask; mask << 1) {
		if (numOfByte != 0) {
			char bit;
			bit = (mask & curr)? '1':'0'; /*Check if the current bit is 1 or 0*/
			strncat(machineCode, &bit, 1); /*Append the bit to the machineCode string*/
			numOfByte--; /*Decrease the number of remaining bytes*/
		}
	}
	strcat(machineCode, "\0"); /*Add the EOF marker to the end of the code*/
	strrev(machineCode); /*change the order of bits to match the actual binary representation*/
    }
}

static char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
 * Encodes a given string using Base64 encoding.
 * @param input: The input string to encode.
 * @param inputLength: The length of the input string.
 * @return: The Base64 encoded string.
 */

char *base64_encode(unsigned char *input, size_t inputLength) {
	size_t outputLength = 4*((inputLength+2)/3;
	char* encodedData = (char*)malloc(outputLength + 1);
	if (encodedData == NULL) {
		return NULL;
	}	
	size_t i, j=0;
	for (i = 0; i < inputLength; i += 3) {
		uint32_t value = 0;
		int count = 0;
		for (j = 0; j < 3; j++) {
			value <<= 8;
			if (i + j < inputLength) {
				value |= input[i + j];
				count++;
			}
		}

		for (j=0; j<4; j++) {
			encoded_data[i*4/3+j] = count > j ? base64_chars[(value >> (6*(3-j))) & 0x3F] : '=';
		}
	}

	encoded_data[output_length] = '\0';
	return encoded_data;
}

/**
 * Encodes a 12-bit binary word into its Base64 representation.
 * @param binaryWord: The 12-bit binary word.
 * @return: The Base64 encoded representation of the word.
 */
char *encode_binary_word_to_base64(uint16_t binaryWord) {
	/*convert the 12-bit binary word to 2 bytes*/
	unsigned char bytes[2];
	bytes[0] = (binaryWord >> 4) & 0xFF;
	bytes[1] = ((binaryWord & 0xF) << 4) & 0xF0;
	return base64_encode(bytes,2);
}
