/*
 * Database.h
 *
 *  Created on: 2016¦~1¤ë22¤é
 *      Author: sjean
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "record.h"
#include "board.h"

namespace CJCU
{

class Database
{
public:
	Database();
	virtual ~Database();

	void write(Record r);
	int getOpt(Board b);
};

} /* namespace CJCU */

#endif /* DATABASE_H_ */
