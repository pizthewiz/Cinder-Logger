# Cinder-Logger
`Cinder-Logger` is a [CinderBlock](http://libcinder.org/) to more carefully control logging via [Boost.Log](http://www.boost.org/doc/libs/1_55_0/libs/log/doc/html/index.html).

### EXAMPLE
```C++
void LumberjackApp::setup() {
    mLogger = Logger::create();
    mLogger->setSeverityLevel(SeverityLevelDebug);
}

void LumberjackApp::keyDown(KeyEvent event) {
    mLogger->LogMessage(SeverityLevelDebug, "key code: " + toString(event.getCode()));
}

void LumberjackApp::mouseDown(MouseEvent event) {
    // this will be ignored
    mLogger->LogMessage(SeverityLevelTrace, "LumberjackApp::mouseDown");
}
```
