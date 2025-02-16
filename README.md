# Smart_gloves


![image](https://github.com/user-attachments/assets/88fa7073-1a9a-416c-bc2b-25d19b0f70ea)

This project presents a communication solution for nonverbal individuals using smart gloves with four flex sensors on the fingers. The sensors detect bending through changes in resistance, converting finger movements into two-bit binary values. These values are combined into an eight-bit binary sequence, which is then translated into ASCII characters to form words and sentences. A microcontroller processes the sensor data, encodes it, and displays the resulting message on an LCD screen, enabling communication without the need for sign language knowledge.



Standards used in this project 

♦	ASCII Encoding - 
            This system involves converting 8-bit binary code obtained from flex sensors into ascii   	code. It obtains the data very quickly as this technique is simple and includes usage of 	less memory resources. It is highly compatible as it is supported by various devices, 	softwares etc.


![image](https://github.com/user-attachments/assets/d45a0b42-c648-4853-bf9f-bcf8b310e872)



1. User initiates the system by manipulating their fingers, with four flex sensors integrated into   the gloves responsible for transmitting 2 bits of data each.
2. The first flex sensor sends "00" when bent beyond a predefined threshold (890), while the                                  second, third, and fourth sensors transmit "01," "10," and "11," respectively.
 3. The 2-bit data from all four flex sensors is concatenated, resulting in 8-bit binary data.
 4. The obtained binary data undergoes ASCII Encoding to generate the corresponding character.
 5. The system displays the character on an LCD screen, ensuring user-friendly comprehension.
 6. The characters continue to be displayed successively until an End of Transmission (EOT)     character is reached.
 7. The EOT signifies the conclusion of the transmission, prompting the displayed text to remain visible for a few seconds before the screen clears.
