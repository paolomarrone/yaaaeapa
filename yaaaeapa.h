/*
 * Dynplug
 *
 * Copyright (C) 2022 Orastron Srl unipersonale
 *
 * Copyright is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Copyright is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Copyright.  If not, see <http://www.gnu.org/licenses/>.
 *
 * File authors: Paolo Marrone
 */

#ifndef YAAAEAPA_H
#define YAAAEAPA_H

// Yet another awesome and extraordinary audio plugin API
// Thought to be used only as dynamic library
// Use yaaaeapa_data to store anything relevant for your plugin.
// If you want more instances of the same plugin, just dlmopen with LM_ID_NEWLM again.

void 	yaaaeapa_init (void);
void  	yaaaeapa_fini (void);
void 	yaaaeapa_set_sample_rate (float sample_rate);
void 	yaaaeapa_reset (void);
void 	yaaaeapa_process (const float** x, float** y, int n_samples);
void 	yaaaeapa_set_parameter (int index, float value);
float 	yaaaeapa_get_parameter (int index);
void 	yaaaeapa_note_on (char note, char velocity);
void 	yaaaeapa_note_off (char note);
void 	yaaaeapa_pitch_bend (int value);
void 	yaaaeapa_mod_wheel (char value);

extern int yaaaeapa_parameters_n;
extern int yaaaeapa_buses_in_n;
extern int yaaaeapa_buses_out_n;
extern int yaaaeapa_channels_in_n;
extern int yaaaeapa_channels_out_n;

// Must be NULLs tolerant
void 	yaaaeapa_get_parameter_info (int index, char** name, char** shortName, char** units, char* out, char* bypass, int* steps, float* defaultValueUnmapped);

#endif
