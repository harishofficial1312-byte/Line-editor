# Line-Editor

## Simple Line Editor in C

A simple command-line text editor developed in C. It allows users to create, view, insert, and delete lines of text using simple commands.

## Features

- Insert a line
- Delete a line
- Display the document
- Quit the editor

## Data Structure

The program uses a dynamic array of strings to store the document lines. This allows the document to grow dynamically when more lines are added.

## Commands

| Command | Description |
|--------|-------------|
| 1 | Insert a line |
| 2 | Delete a line |
| 3 | Display document |
| 4 | Quit |

## Compile

```bash
gcc editor.c -o editor
