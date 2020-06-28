#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include "SDL.h"
#undef main
#else
#include <SDL2/SDL.h>
#endif

int main(int argc, char *argv[]) {
  SDL_AudioSpec spec;
  uint8_t *audio_buf;
  uint32_t audio_len;
  int bytes_per_sample;
  uint32_t loop_start = 0;
  uint32_t loop_end;
  SDL_AudioDeviceID dev;
  if (argc < 2) {
    fputs("usage: aloop audio.wav start_sample [end_sample]\n", stderr);
    return 1;
  }
  if (SDL_Init(SDL_INIT_AUDIO)) {
    fprintf(stderr, "aloop: %s\n", SDL_GetError());
    return 1;
  }
  if (!SDL_LoadWAV(argv[1], &spec, &audio_buf, &audio_len)) {
    fprintf(stderr, "aloop: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }
  bytes_per_sample = SDL_AUDIO_BITSIZE(spec.format) / 8 * spec.channels;
  if (argc > 2) {
    loop_start = strtol(argv[2], NULL, 10) * bytes_per_sample;
  }
  if (argc > 3) {
    loop_end = strtol(argv[3], NULL, 10) * bytes_per_sample;
  } else {
    loop_end = audio_len;
  }
  dev = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
  SDL_QueueAudio(dev, audio_buf, loop_end);
  SDL_PauseAudioDevice(dev, 0);
  while (SDL_GetAudioDeviceStatus(dev) == SDL_AUDIO_PLAYING) {
    if ((int)SDL_GetQueuedAudioSize(dev) <= spec.freq * bytes_per_sample) {
      SDL_QueueAudio(dev, &audio_buf[loop_start], loop_end - loop_start);
    }
    SDL_Delay(100);
  }
  SDL_CloseAudioDevice(dev);
  SDL_FreeWAV(audio_buf);
  SDL_Quit();
  return 0;
}
