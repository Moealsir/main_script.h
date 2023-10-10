#!/bin/bash

clear
echo "#include <unistd.h>
#include "main.h"

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

echo "readme file" > README.md

#!/bin/bash

# Initialize the content of main.h
cat <<EOF > main.h
#ifndef MAIN_H
#define MAIN_H

EOF

# Loop to enter libraries
while true; do
    read -p "Enter a library (or 'q' to exit): " library
    if [ "$library" = "q" ]; then
        break
    else
        echo "#include <$library.h>" >> main.h
    fi
done

# Add a new line gap
echo >> main.h
echo "int _putchar(char c);" >> main.h

# Loop to enter prototypes
while true; do
    read -p "Enter a prototype (or 'q' to exit): " prototype
    if [ "$prototype" = "q" ]; then
        break
    else
        echo "$prototype" >> main.h
    fi
done

# Complete the content of main.h
cat <<EOF >> main.h

#endif
EOF

echo "main.h has been created with the specified libraries and prototypes."

