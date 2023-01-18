/*
 * Copyright (C) 2022-2023  Martin Lund
 * Copyright (C) 2023  DEIF A/S
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#pragma once

#include <stdbool.h>

#define do_ioctl(fd, request, args...) \
{ \
    int status = ioctl(fd, request, ## args); \
    if (status < 0) \
    { \
        fprintf(stderr, "ioctl error: %s\n", strerror(errno)); \
        exit(EXIT_FAILURE); \
    } \
}

bool file_exists(const char *filename);
