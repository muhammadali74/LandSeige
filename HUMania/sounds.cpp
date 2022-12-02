// #include "sounds.hpp"
// #include "game.hpp"

// Sounds *Sounds::instance = NULL;

// Sounds *Sounds::getInstance() {
// 	if (!instance) {
// 		instance = new Sounds();
// 	}
// 	return instance;
// }

// void Sounds::cleanUpInstance() {
// 	if (instance) {
// 		delete instance;
// 		instance = NULL;
// 	}
// }

// Sounds::Sounds():
// 	audioAvailable(true),
// 	enabled(!CommandLineOptions::exists("s","nosound")),
// 	musicEnabled(!CommandLineOptions::exists("m","nomusic")),
// 	initialized(false),
// 	musicPlaying(NONE)
// {
// 	if (enabled || musicEnabled) {
// 		initialize();
// 	}
// }

// void Sounds::initialize() {
// 	int audio_rate = 44100;
// 	Uint16 audio_format = AUDIO_S16SYS;
// 	int audio_channels = 2;
// 	int audio_buffers = 2048;

// 	if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
// 		std::cout << "SDL audio initialization failed (SDL_InitSubSystem): " << SDL_GetError() << std::endl;
// 		audioAvailable = false;
// 	}

// 	if (audioAvailable && Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
// 		std::cerr << "Unable to initialize audio (MixOpenAudio): " << Mix_GetError() << std::endl;
// 		audioAvailable = false;
// 	}
// 	if (audioAvailable) {
// 		music_intro = loadWaveMusic("sounds/intro.wav");
// 		initialized = true;
// 	} else {
// 		enabled      = false;
// 		musicEnabled = false;
// 	}
// }

// Sounds::~Sounds() {
// 	if (initialized) {
// 		Mix_HaltChannel(-1);
// 		Mix_HaltMusic();
// 		SAFE_FREE_MUSIC(music_intro);
// 		Mix_CloseAudio();
// 		SDL_QuitSubSystem(SDL_INIT_AUDIO);
// 	}
// }

// void Sounds::playIntro() {
// 	if(musicEnabled && musicPlaying != INTRO && music_intro) {
// 		stopMusic();
// 		if(Mix_PlayMusic(music_intro,1) == -1)
// 			std::cerr << "Unable to play WAV file: " << Mix_GetError() << std::endl;
// 		musicPlaying = INTRO;
// 	}
// }

// void Sounds::stopMusic() {
// 	if(Mix_PlayingMusic())
// 		Mix_HaltMusic();
// 	musicPlaying = NONE;
// }

// Mix_Music *Sounds::loadWaveMusic(const char *filename) {
// 	char filePath[256];
// 	getFilePath(filePath, filename);
// 	Mix_Music *music = Mix_LoadMUS(filePath);
// 	if (!music) {
// 		std::cerr << "Unable to load wave music file (" << filename << "): " << Mix_GetError() << std::endl;
// 	}
// 	return music;
// }