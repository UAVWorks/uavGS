//
// Created by mirco on 25.06.20.
//

#ifndef UAVGS_SENSORDATAMANAGER_H
#define UAVGS_SENSORDATAMANAGER_H

#include <cpsCore/cps_object>
#include <uavAP/Core/SensorData.h>
#include <uavAP/Core/Frames/VehicleOneFrame.h>

#include <boost/signals2.hpp>

class DataHandling;
class GSWidgetFactory;

class SensorDataManager: public AggregatableObject<DataHandling, GSWidgetFactory>, public IRunnableObject
{
public:

	static constexpr TypeId typeId = "sensor_data";

	bool
	run(RunStage stage) override;

	using OnSensorData = boost::signals2::signal<void(const SensorData&)>;

	boost::signals2::connection
	subscribeOnSensorDataLocal(const OnSensorData::slot_type& slot);

	boost::signals2::connection
	subscribeOnSensorDataGlobal(const OnSensorData::slot_type& slot);

private:

	void
	onSensorData(const SensorData& sd);

	SensorData sensorDataLocal_;
	SensorData sensorDataGlobal_;
	VehicleOneFrame localFrame_;

	OnSensorData onSensorDataLocal_;
	OnSensorData onSensorDataGlobal_;


};


#endif //UAVGS_SENSORDATAMANAGER_H