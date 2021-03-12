Name: Cole DiStasio

OS: Windows

Solution: VirtualBox

Text Editor: Emacs

Hours to Complete: roughly 6-7 hours

Help: None

Problems: Didn't encounter any major problems except sound initially wouldn't play in GuitarHeroLite and I ended up having to use headphones to hear any sound.

About this assignment: In this assignment I implemented a keyboard that you could play using computer keys that produced guitar-like sounds. I made a ring buffer, which holds guitar string position data, when the string would be plucked. Next I  created a guitar string class which has an inner ring buffer. The guitar string can perform functions like pluck, and tic. Pluck simulates plucking the guitar string with a certain velocity. Tic is a function that mimics how the sound is produced when plucked using the Karplus-Strong algorithm. After simulating tic’s at different frequencies, I then converted them to sound buffers, and added a keyboard listener. The keyboard listener would listen to speciﬁed keys, and play the corresponding note. 
