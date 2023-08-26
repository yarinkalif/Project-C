#ifndef BINARY_H
#define BINARY_H

/**
 * Represents the given assembly line instruction in binary format.
 * 
 * @param machineCode: The output binary representation of the instruction.
 * @param keyWord: Assembly instruction keyword (e.g., "MOV", "ADD").
 * @param operands: The operands for the instruction.
 * @param numberLine: The line number of the instruction in the assembly file.
 */
void line_instruction_binary(char *machineCode, char *keyWord, char *operands, int numberLine);

/**
 * Identifies the type of the operand (e.g., REGISTER, NUMBER, STRING, LABEL).
 * 
 * @param operand: The operand string to identify.
 * @return: The type of operand.
 */
OperandType identify_operand_type(char *operand);

/**
 * Creates the instruction for group 1, which involves two operands.
 * 
 * @param keyword: Assembly instruction keyword.
 * @param operands: The operands for the instruction.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 1 instruction.
 */
instructionGroup1 create_instruction_1(char *keyword, char *operands, int currOpcode, int typeOfKeyWord, int numberLine);

/**
 * Creates the instruction for group 2, which involves two operands.
 * 
 * @param keyword: Assembly instruction keyword.
 * @param operands: The operands for the instruction.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 2 instruction.
 */
instructionGroup2 create_instruction_2(char *keyword, char *operands, int currOpcode, int typeOfKeyWord, int numberLine);

/**
 * Creates the instruction for group 3, which doesn't involve operands.
 * 
 * @param keyword: Assembly instruction keyword.
 * @param currOpcode: The opcode for the instruction.
 * @param typeOfKeyWord: The type of keyword.
 * @param numberLine: The line number of the instruction.
 * @return: The binary representation for group 3 instruction.
 */
instructionGroup3 create_instruction_3(char *keyword, int currOpcode, int typeOfKeyWord, int numberLine);

/**
 * Represents the given assembly guidance in binary format.
 * 
 * @param machineCode: The output binary representation.
 * @param keyWord: Assembly guidance keyword (e.g., "DATA", "STRING").
 * @param dataList: The data for the guidance.
 * @param typeOfGuidence: The type of guidance.
 * @param numberLine: The line number of the guidance in the assembly file.
 */
void line_guidence_binary(char *machineCode, char *keyWord, long dataList,int typeOfGuidence, int numberLine);

/**
 * Converts the given integer into its binary representation.
 * 
 * @param machineCode: The output binary string.
 * @param curr: The integer to convert.
 * @param numOfBit: The number of bits in the integer.
 */
void int_to_binary(char *machineCode, int curr, int numOfBit);

/**
 * Encodes a given string using Base64 encoding.
 * 
 * @param input: The input string to encode.
 * @param inputLength: The length of the input string.
 * @return: The Base64 encoded string.
 */
char *base64_encode(unsigned char *input, size_t inputLength);

/**
 * Encodes a 12-bit binary word into its Base64 representation.
 * 
 * @param binaryWord: The 12-bit binary word.
 * @return: The Base64 encoded representation of the word.
 */
char *encode_binary_word_to_base64(uint16_t binaryWord);

#endif /* BINARY_H */
