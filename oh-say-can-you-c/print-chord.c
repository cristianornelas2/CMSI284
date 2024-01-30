//
//  main.c
//  print-chord
//
//  Created by Cristian Ornelas on 4/9/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "notes.h"

#define INVALID -1

// ***** IMPLEMENT ME! *****
void print_chord(int note_index, int chord_index) {
    printf("%s%s: ", NOTES[note_index], CHORD_SUFFIXES[chord_index]); // Cm7:
    printf("%s ", NOTES[note_index]);
    
    for (int i = 0; i < CHORD_STEP_COUNT[chord_index] ; i++) {
        int result = note_index + CHORD_STEPS[chord_index][i];
        int next_index = result % NOTE_COUNT;
        printf("%s ",NOTES[next_index]);// Cm7: C Eb G Bb
        note_index = next_index;
    }
    puts("");
}


// ***** Feel free to add more functions if you think they will make it easier to check argument validity.
int main(int argc, char** sargv) {
    char *ptr=NULL;
         errno = 0;
    if(argc!= 3){
        printf("This program requires exactly two command line arguments:\n");
        printf("The NOTES index and the CHORD_SUFFIXES index of the note and chord suffix to print, respectively.\n");
        return INVALID;
    }
    
    int note_index = strtol(sargv[1], &ptr, 10);
    int chord_index = strtol(sargv[2], &ptr, 10);
    
        if (errno == EINVAL){
        printf("Either %s or %s is not a valid index.\n", sargv[1], sargv[2]);
            return INVALID;
    }
        if (note_index > NOTE_COUNT-1 || chord_index > CHORD_COUNT-1){
            printf("Either %s or %s is out of range.\n", sargv[1], sargv[2]);
            return INVALID;
    }
    print_chord(note_index, chord_index);
    
    return 0;
}
