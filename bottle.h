#ifndef BOTTLE_H
#define BOTTLE_H

class Bottle{
    private:
        int max_volume;
        int current_volume;
    public:
        Bottle();
        Bottle(int);
        int max() { return max_volume; }
        int volume() { return current_volume; }
        void dump() { current_volume = 0; }
        void fill() { current_volume = max_volume; }
        void set(int volume) { current_volume = volume; }
        int add(Bottle);
};

#endif /*BOTTLE_H*/
