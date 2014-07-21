# Cinder-Logger
`Cinder-Logger` is a [CinderBlock](http://libcinder.org/) to more carefully control logging via [Boost.Log](http://www.boost.org/doc/libs/1_55_0/libs/log/doc/html/index.html). Binaries are provided to support OS X and the block requires the *dev* branch of [Cinder](https://github.com/cinder/Cinder/tree/dev).

### EXAMPLE
```C++
void LumberjackApp::setup() {
    mLogger = Logger::create();
    mLogger->setSeverityLevel(SeverityLevel::Debug);
}

void LumberjackApp::shutdown() {
    mLogger->logFatal("💀");
}

void LumberjackApp::keyDown(KeyEvent event) {
    mLogger->logMessage(SeverityLevel::Debug, "key code: " + toString(event.getCode()));
}

void LumberjackApp::mouseDown(MouseEvent event) {
    // ignored as the severity level is lower than the threshold
    mLogger->logMessage(SeverityLevel::Trace, "LumberjackApp::mouseDown");
}
```
