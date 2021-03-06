#ifndef CHARTPLAYER_H_INCLUDED
#define CHARTPLAYER_H_INCLUDED

#include "../global/config.h"
#include "../global/state.h"
#include "../utilities/musicPlayer.h"
#include "../math/fraction.h"
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std;

typedef Fraction<int,int> Beat; // Time point
typedef double BeatDuration; // Duration
typedef Fraction<int,int> BPM;

/** A value type class that simply stores when a note is */
class Note
{
public:
	const Beat beat;
	// speed (is currently just constant)
	Note(Beat);
};

bool earlierThan(const Note*,const Note*);

class ChartPlayer
{
private:
	// MusicPlayer* music;
	chrono::high_resolution_clock::time_point startTime;
	/** Indicates when the first beat goes in the song */
	Milliseconds songOffset;
	BPM bpm;
	list<Note*> notes;
	vector<Judgement> judgements;
	void registerMisses();
public:
	// ChartPlayer(MusicPlayer&, istream& data);
	ChartPlayer(istream& data);
	void start();
	const vector<pair<BeatDuration,Note*>> getNotePositions(BeatDuration = 8);
	void hit();
	const vector<Judgement>& getJudgements();
};

#include "chartPlayer.cpp"

#endif // CHARTPLAYER_H_INCLUDED
