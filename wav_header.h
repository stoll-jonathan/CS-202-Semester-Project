//struct to hold the header and metadata of a wav file
#ifndef WAV_HEADER
#define WAV_HEADER

typedef struct wav_header {
    //riff header
    char riff_header[4];    //should be "RIFF"
    int file_size;
    char wave_header[4];    //should be "WAVE"

    //format header
    char fmt_header[4];     //should be "fmt"
    int fmt_chunk_size;     //should be 16
    short audio_format;     //should be 1 or 3
    short num_channels;     //1 for mono, 2 for stereo
    int sample_rate;
    int byte_rate;          //bytes per second (sample_rate * num_channels * bytes per sample)
    short sample_alignment; //num_channels * Bytes Per Sample
    short bit_depth;        //num of bits per sample

    //data
    char data_header[4];    //should be "data"
    int num_data_bytes;     //num of bytes in data (num of samples * num_channels * sample byte size)
} wav_header;

#endif

