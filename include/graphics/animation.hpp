#ifndef animation_hpp
#define animation_hpp

#include <stdio.h>
#include "spritesheet.hpp"

/**
 * Contains an animation sequence of sprite frames
 */
class Animation {
    public:
        float frames_per_second;
        SpriteFrame* frames;
        std::size_t num_frames;

        /** spritesheet used to create the animation */
        SpriteSheet* spritesheet;

        std::size_t getNumFrames();
        float getTotalDuration();
};

#endif /* animation_hpp */
