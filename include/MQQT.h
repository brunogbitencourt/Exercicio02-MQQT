#pragma once
#include <string>

using namespace std;

class MQQT
{
    private:
        string server;
        int port;
        string client;
        string topic;
        string payload;
        int qos;
        bool retain;
        int keepAlive;
        bool cleanSession;
        string willTopic;
        string willPayload;
        int willQos;
        bool willRetain;
        bool willFlag;
        string clientId;
        string userName;
        string password;
    

    public:
        MQQT();
        ~MQQT();
        void connect();
        void disconnect();
        void publish();
        void subscribe();
        void callback();
        void loop();
        void setServer();
        void setPort();
        void setClient();
        void setTopic();
        void setPayload();
        void setQos();
        void setRetain();
        void setKeepAlive();
        void setCleanSession();
        void setWillTopic();
        void setWillPayload();
        void setWillQos();
        void setWillRetain();
        void setWillFlag();
        void setClientId();
        void setUserName();
        void setPassword();




};
