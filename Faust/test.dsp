import("stdfaust.lib");

length = nentry("lenght", 0, 0, 1, 0.01);

process tube = _ <: ((+ : tubeDelay)~_ , _ ) : ( _+_ )
with {
	tubeDelay = fdelay(4096, 2* (length1 * SR) / (343.54) );
};
