#!/bin/sh
id $FT_USER -G -n | tr -s " " "," | tr -d "\n"