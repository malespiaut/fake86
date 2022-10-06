/*
  Imagegen: A blank disk image generator for use with Fake86
  Copyright (C)2010-2012 Mike Chambers

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BUILD "Imagegen v1.1"

int32_t
main(const int32_t argc, const char* argv[])
{
  printf("%s (c)2010-2012 Mike Chambers\n", BUILD);
  puts("[Blank disk image generator for Fake86]\n\n");

  if (argc < 3)
    {
      puts("Usage syntax:\n");
      puts("    imagegen imagefile size\n\n");
      puts("imagefile denotes the filename of the new disk image to create.\n");
      puts("size denotes the size in megabytes that it should be.\n");
      return EXIT_FAILURE;
    }

  size_t size = atoi(argv[2]);
  if ((size > 503) || !size)
    {
      puts("Invalid size specified! Valid range is 1 to 503 MB.\n");
      return EXIT_FAILURE;
    }

  FILE* image = fopen(argv[1], "wb");
  if (!image)
    {
      printf("Unable to create new file: %s\n", argv[1]);
      return EXIT_FAILURE;
    }

  char* blank = (void*)malloc(1048576);
  if (!blank)
    {
      puts("Unable to allocate enough memory!\n");
      return EXIT_FAILURE;
    }

  printf("Please wait, generating new image...\n");

  for (size_t i = 0; i < size; ++i)
    {
      fwrite(&blank[0], 1048576, 1, image);
      printf("\rWriting to file: %lu MB", i);
    }

  puts(" complete.\n");
  return EXIT_SUCCESS;
}
