#ifndef SIM_INPUTS_H
#define SIM_INPUTS_H

typedef struct sim_parameters { // Struct to hold the simulation parameters that are required for the simulation
    int max_parking_spaces; // Maximum number of parking spaces
    int max_parking_time; // Maximum parking time for a vehicle
    int time_steps; // Total number of time steps for the simulation
    int arrival_probability; // Probability of a vehicle arriving at the parking lot in each time step (0-100)
    int rand_seed; // Random seed for generating random numbers, to allow for reproducibility of the simulation results
}sim_parameters;


/** 
 * @brief Reads an integer input from the user with validation
 * 
 * Prompts the user for input and validates that it is an integer within the specified range. 
 * If the input is invalid, it will continue to prompt the user until a valid input is received.
 * 
 * @param prompt The message to display to the user when asking for input
 * @param min The minimum valid value for the input (inclusive), set to -1 if there is no minimum
 * @param max The maximum valid value for the input (inclusive), set to -1 if there is no maximum
 * @return int The validated integer input from the user
 */
int get_int(const char *prompt, int min, int max); 

/**s
 * @brief Reads the simulation inputs from the user
 * 
 * Gets the simulation parameters from the user and returns it as a SimInputs struct. 
 * 
 * @return SimInputs Pointer to the struct containing the simulation parameters, NULL if there was an error during input reading or conversion
 */
sim_parameters *get_inputs();

#endif // SIM_INPUTS_H