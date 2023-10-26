#!/bin/bash

#create _putchar.c file
echo "#include <unistd.h>
#include \"main.h\"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}" > _putchar.c

#create README.md file
echo "readme file" > README.md

#create main.h file
# Ask the user for the name of the header file
read -p "Enter the name of the header file (without extension): " header_name

# Add '.h' extension to the header file name
header_file="${header_name}.h"

# Initialize the content of the header file
cat <<EOF > "$header_file"
#ifndef ${header_name^^}_H
#define ${header_name^^}_H

EOF

# Loop to enter libraries
while true; do
    read -p "Enter a library (or 'q' to exit): " library
    if [ "$library" = "q" ]; then
        break
    else
        echo "#include <$library.h>" >> "$header_file"
    fi
done

# Add a new line gap
echo >> "$header_file"
echo "int _putchar(char c);" >> "$header_file"

# Loop to enter prototypes
while true; do
    read -p "Enter a prototype (or 'q' to exit): " prototype
    if [ "$prototype" = "q" ]; then
        break
    else
        echo "$prototype" >> "$header_file"
    fi
done

# Complete the content of the header file
cat <<EOF >> "$header_file"

#endif
EOF

echo "$header_file has been created with the specified libraries and prototypes."

