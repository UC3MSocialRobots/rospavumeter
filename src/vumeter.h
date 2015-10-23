#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <signal.h>

#include <glib.h>
#include <glibmm.h>

#include <pulse/pulseaudio.h>
#include <pulse/glib-mainloop.h>

#include <ros/ros.h>
#include <std_msgs/Float64.h>

//~ #include "system/system_utils.h"
 
#define LOGARITHMIC 1


class MainWindow{

public:
    MainWindow(const pa_channel_map &map, const char *source_name, const char *description);
    virtual ~MainWindow();
    
protected:

    class ChannelInfo {
    public:
        ChannelInfo(MainWindow &w, const Glib::ustring &l);
        double progress;
    };

    std::vector<ChannelInfo*> channels;

    float *levels;

    virtual void addChannel(const Glib::ustring &l);
//    virtual bool on_delete_event(GdkEventAny* e);
    virtual bool on_display_timeout();
    virtual bool on_calc_timeout();
    virtual void decayLevels();

    sigc::connection display_timeout_signal_connection;
    sigc::connection calc_timeout_signal_connection;
    pa_usec_t latency;

    class LevelInfo {
    public:
        LevelInfo(float *levels, pa_usec_t l);
        virtual ~LevelInfo();
        bool elapsed();

        struct timeval tv;
        float *levels;
    };

    std::deque<LevelInfo *> levelQueue;

public:
    //~ virtual float getMasterVolume();
    virtual void pushData(const float *d, unsigned l);
    virtual void showLevels(const LevelInfo& i);
    virtual double globalSoundAverage(const LevelInfo &i);
    virtual void updateLatency(pa_usec_t l);
};

static enum {
    PLAYBACK,
    RECORD
} mode = PLAYBACK;

static MainWindow *mainWindow = NULL;
static pa_context *context = NULL;
static pa_stream *stream = NULL;
static char* device_name = NULL;
static char* device_description = NULL;

//ros_vars
ros::Publisher systemSoundLevelPublisher;
//~ mouth::SystemSoundLevel systemSoundLevel;
//~ std_msgs::Float64 systemSoundLevel;
//end ros_vars
