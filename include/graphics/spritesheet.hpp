#ifndef spritesheet_hpp
#define spritesheet_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include "json.hpp"

struct SpriteSheetData {
    std::string* images;
    
    /* The array of frames, which hold locations of different sprites in the spritesheet */
    SDL_Rect* frames;
    
    /* The total number of frames */
    int num_frames = 0;
    
    /* The mapping of frame names to their indices in frame_list */
    std::map<std::string, int> frame_indices;

};

struct SpriteFrame {
    SDL_Rect rect;    // frame rectangle
    int image_index;  // specifies the index of the source image
    int reg_x;        // registration point of the frame
    int reg_y;
};

class SpriteSheet {
public:
    /** path to image file */
    std::string image_path;
    
    /** image width */
    int width;
    
    /** image height */
    int height;
    
    struct SpriteFrame {
        std::string frame_name;
        
        SDL_Rect sprite_pos_in_sheet;
        SDL_Rect sprite_size_in_sheet;
        
        SDL_Rect sprite_source_pos;
        SDL_Rect sprite_source_size;
        
        SDL_Rect image_source_size;
        
        SDL_Point pivot;
        
        bool rotated;
        bool trimmed;
    };
     
    /** The array of frames, which hold locations of different sprites in the spritesheet */
    SpriteFrame* frames;
    
    /** The total number of frames */
    std::size_t num_frames = 0;
    
    /** The mapping of frame names to their indices in frame_list */
    std::map<std::string, int> frame_names;
    
    void Draw(SDL_Renderer* renderer, SpriteFrame* frame);
        
    void loadSpriteSheet(std::string filename);
private:
    SDL_Texture* texture;
};

#endif /* spritesheet_hpp */
