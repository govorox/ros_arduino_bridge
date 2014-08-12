/* *************************************************************
   Encoder definitions
   
   Add a "#if defined" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

#if defined ROBOGAIA
  /* The Robogaia Mega Encoder shield */
  #include "MegaEncoderCounter.h"

  /* Create the encoder shield object */
  MegaEncoderCounter encoders = MegaEncoderCounter(4); // Initializes the Mega Encoder Counter in the 4X Count mode
  
  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return encoders.YAxisGetCount();
    else return encoders.XAxisGetCount();
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT) return encoders.YAxisReset();
    else return encoders.XAxisReset();
  }
#else
  // No Encoder defined
  //#error A encoder driver must be selected!
  
  long encoders[2];
  
  long readEncoder(int i) {
    if (i == LEFT)
      return encoders[0];
    if (i == RIGHT)
      return encoders[1];
    return 0;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT)
      encoders[0] = 0;
    if (i == RIGHT)
      encoders[1] = 0;
  }
  
  void adjustEncoder(int i, long ticks) {
    if (i == LEFT)
      encoders[0] += ticks;
    if (i == RIGHT)
      encoders[1] += ticks;
  }
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

