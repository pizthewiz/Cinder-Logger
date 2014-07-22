//
//  Logger.h
//  Cinder-Logger
//
//  Created by Jean-Pierre Mouilleseaux on 09 Apr 2014.
//  Copyright 2014 Chorded Constructions. All rights reserved.
//

#pragma once

namespace Cinder { namespace Logger {

enum class SeverityLevel {Trace, Debug, Info, Warning, Error, Fatal};

typedef std::shared_ptr<class Logger> LoggerRef;

class Logger : public std::enable_shared_from_this<Logger> {
public:
    static LoggerRef create();
    ~Logger();

    void setSeverityLevel(SeverityLevel level);
    SeverityLevel getSeverityLevel() const { return mSeverityLevel; }

    void setLogFilePath(const ci::fs::path& path);
    ci::fs::path getLogFilePath() const { return mLogFilePath; }

    void logMessage(const SeverityLevel level, const std::string& message);
    void logTrace(const std::string& message);
    void logDebug(const std::string& message);
    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    void logFatal(const std::string& message);

private:
    Logger();

    SeverityLevel mSeverityLevel;
    ci::fs::path mLogFilePath;
};

}}
