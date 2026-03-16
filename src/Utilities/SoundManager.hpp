#pragma once
#include "raylib-cpp/raylib-cpp.hpp"

class SoundManager {
    public:
    static inline Sound attack;
    static inline Sound dead;
    static inline Sound gameOver;
    static inline Sound hit;
    static inline Sound shoot;
    static inline Music music;
    static inline bool musicLoaded = false;

    static void Load() {
        attack = LoadSound("audio/attack.mp3");
        dead = LoadSound("audio/dead.mp3");
        gameOver = LoadSound("audio/gameOver.mp3");
        hit = LoadSound("audio/hit.mp3");
        shoot = LoadSound("audio/shoot.mp3");
        music = LoadMusicStream("audio/Heaven Pierce Her - ULTRAKILL- VIOLENCE - 08 War Without Reason.mp3");
        SetMusicVolume(music, 0.2f);
        musicLoaded = true;
    }

    static void Unload() {
        StopMusic();
        UnloadSound(attack);
        UnloadSound(dead);
        UnloadSound(gameOver);
        UnloadSound(hit);
        UnloadSound(shoot);
        UnloadMusicStream(music);
        musicLoaded = false;
    }

    static void PlayMusic() {
        if (!musicLoaded) return;
        if (!IsMusicStreamPlaying(music)) {
            PlayMusicStream(music);
        }
    }

    static void UpdateMusic() {
        if (!musicLoaded) return;
        UpdateMusicStream(music);
    }

    static void PauseMusic() {
        if (!musicLoaded) return;
        if (IsMusicStreamPlaying(music)) {
            PauseMusicStream(music);
        }
    }

    static void ResumeMusic() {
        if (!musicLoaded) return;
        if (!IsMusicStreamPlaying(music)) {
            ResumeMusicStream(music);
        }
    }

    static void StopMusic() {
        if (!musicLoaded) return;
        StopMusicStream(music);
    }

    static bool IsPlaying() {
        return musicLoaded && IsMusicStreamPlaying(music);
    }
};
