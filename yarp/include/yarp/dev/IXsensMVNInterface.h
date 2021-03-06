/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef YARP_DEV_IXSENSMVNINTERFACE_H
#define YARP_DEV_IXSENSMVNINTERFACE_H

#include <yarp/dev/api.h>

#include <map>
#include <string>

namespace yarp {
    namespace experimental {
        namespace dev {
            class IXsensMVNInterface;
        }
    } // namespace experimental
} // namespace yarp

/**
 * \since 2.3.69
 */
class yarp::experimental::dev::IXsensMVNInterface
{
public:
    virtual ~IXsensMVNInterface();
    // Configuration
    virtual bool setBodyDimensions(const std::map<std::string, double>& dimensions) = 0;
    virtual bool setBodyDimension(const std::string& bodyPart, const double dimension) = 0;
    virtual std::map<std::string, double> bodyDimensions() = 0;

    // Calibration methods
    virtual bool calibrate(const std::string& calibrationType = "") = 0;
    virtual bool abortCalibration() = 0;

    // Acquisition methods
    virtual bool startAcquisition() = 0;
    virtual bool stopAcquisition() = 0;
};

#endif /* end of include guard: YARP_DEV_IXSENSMVNINTERFACE_H */
