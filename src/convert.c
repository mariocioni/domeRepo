/*
 * convert.c
 * 
 * Copyright 2020 dome <>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
long tosec(long k);

int main(int argc, char **argv)
{
	long t=122231;
	printf("to sec is %ld\n",tosec(t)); 
	return 0;
}

long tosec(long k){
	long tmp=k/10000;
	long h=tmp*3600;
	tmp*=10000;
	tmp=k-tmp;
	long m=tmp/100; 
	long sec = tmp-m*100;
	m*=60;
	return (sec+h+m);
}
