#include "Block.h"

map<string, int> Block::week = {{"Monday", 2}, {"Tuesday", 3}, {"Wednesday", 4},
                                {"Thursday", 5}, {"Friday", 6}}; 

/**
 * @brief Construct a new Block:: Block object
 * @param code code of the UC
 * @param weekday day of the week
 * @param startHour start hour of the class (aula)
 * @param duration duration of the class (aula)
 * @param type type of the class (aula)
 */
Block::Block(string code, string weekday, string startHour, string duration, string type) :
             code_(code), weekday_(weekday), type_(type) {
    startHour_ = stof(startHour);
    endHour_ = stof(startHour) + stof(duration);
}

/**
 * @brief returns the code of the UC
 * @return string with the code of the UC
 */
string Block::get_code() const{
    return code_;
}

/**
 * @brief returns the day of the week
 * @return string day of the week
 */
string Block::get_weekday() const{
    return weekday_;
}

/**
 * @brief returns the start hour of the class (aula)
 * @return float start hour of the class (aula)
 */
float Block::get_startHour() const{
    return startHour_;
}

/**
 * @brief returns the end hour (start hour plus the duration) of the class (aula)
 * @return float end hour of the class (aula)
 */
float Block::get_endHour() const{
    return endHour_;
}

/**
 * @brief returns the type of the class (aula)
 * @return string type of the class (aula)
 */
string Block::get_type() const{
    return type_;
}

/**
 * @brief compares a block to other block
 * @param b block to be compared to
 * @return true if the block to be compared to happens after the other block
 * @return false if the block to be compared to happens before the other block
 */
bool Block::operator<(const Block& b) const{
    if (weekday_ == b.get_weekday()){
        return (startHour_ < b.get_startHour());
    }
    
    return (Block::week[weekday_] < Block::week[b.get_weekday()]);
}