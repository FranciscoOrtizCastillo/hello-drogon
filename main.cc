#include <drogon/drogon.h>
#include <drogon/HttpResponse.h>

//using namespace drogon; //O usar siempre drogon::

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555);
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //drogon::app().loadConfigFile("../config.yaml");

    //drogon::HttpAppFramework::instance()
    drogon::app().registerHandler("/list_para",
                        [=](const drogon::HttpRequestPtr &req,
                            std::function<void (const drogon::HttpResponsePtr &)> &&callback)
                        {
                            auto para=req->getParameters();
                            drogon::HttpViewData data;
                            data.insert("title","ListParameters");
                            data.insert("parameters",para);
                            auto resp=drogon::HttpResponse::newHttpViewResponse("ListParameters.csp",data);
                            callback(resp);
                        });

    using Callback = std::function<void (const drogon::HttpResponsePtr &)> ;
    drogon::app().registerHandler("/hello", [](const drogon::HttpRequestPtr& req, Callback &&callback)
    {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello World");
        callback(resp);
    });

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
