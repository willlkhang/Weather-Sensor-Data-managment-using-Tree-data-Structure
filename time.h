// Time.h

//---------------------------------------------------------------------------------

#ifndef TIME_H
#define TIME_H

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

	/**
	 * @class Time
	 * @brief Represents a time for sensor data records
	 *
	 * Stores a time with hour and minute components, providing getter and setter
	 * methods for each.
	 * Used to timestamp sensor measurements in a sensor log.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add validation for hour (0-23) and minute (0-59)
	 * @bug Setters do not validate input values
	 */
class Time{
public:
        /**
         * @brief Default constructor.
         *
         * Initializes hour and minute to zero.
         */
    Time();

        /**
         * @brief Parameterized constructor.
         *
         * Initializes the time with specified hour and minute values.
         *
         * @param h The hour (0–23).
         * @param m The minute (0–59).
         */
    Time(int h, int m);

        /**
         * @brief Sets the hour.
         * @param h The hour to set (0–23).
         */
    void SetHour(int h);

        /**
         * @brief Gets the hour.
         * @return The current hour value.
         */
    int GetHour() const;

        /**
         * @brief Sets the minute.
         * @param m The minute to set (0–59).
         */
    void SetMinute(int m);

        /**
         * @brief Gets the minute.
         * @return The current minute value.
         */
    int GetMinute() const;

private:
    /// Hour of the day (0-23)
    int hour;
    /// Minute of the hour (0-59)
    int minute;
};

#endif // TIME_H
