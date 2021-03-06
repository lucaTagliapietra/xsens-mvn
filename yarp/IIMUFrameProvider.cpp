/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#include "IIMUFrameProvider.h"

#include <algorithm>

namespace yarp {
    namespace experimental {
        namespace dev {

            bool IMUFrameReference::operator==(const IMUFrameReference& frame) const
            {
                return frame.IMUframeName == this->IMUframeName
                       && frame.IMUframeReference == this->IMUframeReference;
            }

            IIMUFrameProvider::~IIMUFrameProvider() {}

            unsigned IIMUFrameProvider::getIMUFrameCount() { return IMUFrames().size(); }

            IMUFrameReference IIMUFrameProvider::IMUFrameAtIndex(unsigned IMUFrameIndex)
            {
                if (IMUFrameIndex >= getIMUFrameCount()) {
                    IMUFrameReference dummy = {"", ""};
                    return dummy;
                }
                return IMUFrames()[IMUFrameIndex];
            }

            int IIMUFrameProvider::IMUFrameIndexForIMUFrame(const IMUFrameReference& frame)
            {
                std::vector<IMUFrameReference> frames = this->IMUFrames();
                std::vector<IMUFrameReference>::iterator found =
                    std::find(frames.begin(), frames.end(), frame);
                if (found == frames.end())
                    return -1;
                return std::distance(frames.begin(), found);
            }

            IIMUFrameProviderStatus IIMUFrameProvider::getIMUFrameInformation(
                std::vector<yarp::sig::Vector>& imuOrientations,
                std::vector<yarp::sig::Vector>& imuAngularVelocities,
                std::vector<yarp::sig::Vector>& imuLinearAccelerations,
                std::vector<yarp::sig::Vector>& imuMagneticFields)
            {
                IIMUFrameProviderStatus status = getIMUFrameOrientations(imuOrientations);
                if (status != IIMUFrameProviderStatusOK) {
                    return status;
                }
                status = getIMUFrameAngularVelocities(imuAngularVelocities);
                if (status != IIMUFrameProviderStatusOK) {
                    return status;
                }
                status = getIMUFrameLinearAccelerations(imuLinearAccelerations);
                if (status != IIMUFrameProviderStatusOK) {
                    return status;
                }
                return getIMUFrameMagneticFields(imuMagneticFields);
            }
        } // namespace dev
    } // namespace experimental
} // namespace yarp
