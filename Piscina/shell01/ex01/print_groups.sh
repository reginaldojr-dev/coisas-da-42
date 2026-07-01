#!/bin/sh

export FT_USER=bocal

id -nG "$FT_USER" | tr ' ' ','

