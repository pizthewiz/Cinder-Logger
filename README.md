# Cinder-Logger
`Cinder-Logger` is a [CinderBlock](http://libcinder.org/) to more carefully control logging via [Boost.Log](http://www.boost.org/doc/libs/1_55_0/libs/log/doc/html/index.html). Binaries are provided to support OS X and the cinderblock requires the *dev* branches of [Cinder](https://github.com/cinder/Cinder/tree/dev) and the [Cinder-Boost](https://github.com/cinder/Cinder-Boost/tree/dev) submodule.

### EXAMPLE
```C++
void LumberjackApp::setup() {
    mLogger = Logger::create();
    mLogger->setSeverityLevel(SeverityLevelDebug);
}

void LumberjackApp::shutdown() {
    mLogger->logFatal("💀");
}

void LumberjackApp::keyDown(KeyEvent event) {
    mLogger->logMessage(SeverityLevelDebug, "key code: " + toString(event.getCode()));
}

void LumberjackApp::mouseDown(MouseEvent event) {
    // this will be ignored
    mLogger->logMessage(SeverityLevelTrace, "LumberjackApp::mouseDown");
}
```
