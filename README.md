# Cinder-Logger
`Cinder-Logger` is a [CinderBlock](http://libcinder.org/) to more carefully control logging via [Boost.Log v2](http://www.boost.org/doc/libs/1_55_0/libs/log/doc/html/index.html). Binaries are provided to support OS X and the block is designed for use with the 0.8.6 of Cinder.

**NOTE** the heir apparent Cinder branch, [glNext](https://github.com/cinder/Cinder/tree/glNext) includes [Log.h](https://github.com/cinder/Cinder/blob/glNext/include/cinder/Log.h) which should be used instead of `Cinder-Logger`, it does not rely so heavily on Boost and has a much more rich feature set - you might even consider using a [backported version](https://forum.libcinder.org/#Topic/23286000002343041) if you are still running Cinder-0.8.6.

### EXAMPLE
```C++
void LumberjackApp::setup() {
    mLogger = Logger::create();
    fs::path path = expandPath("~/Desktop/lumberjack.log");
    mLogger->setLogFilePath(path);
    mLogger->setSeverityLevel(Logger::SeverityLevel::Debug);
}

void LumberjackApp::shutdown() {
    mLogger->logFatal("💀");
}

void LumberjackApp::keyDown(KeyEvent event) {
    mLogger->logMessage(Logger::SeverityLevel::Debug, "key code: " + toString(event.getCode()));
}

void LumberjackApp::mouseDown(MouseEvent event) {
    // ignored as the severity level is lower than the threshold
    mLogger->logMessage(Logger::SeverityLevel::Trace, "LumberjackApp::mouseDown");
}
```
