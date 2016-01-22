/*
 * Record.h
 *
 *  Created on: 2016¦~1¤ë22¤é
 *      Author: sjean
 */

#ifndef RECORD_H_
#define RECORD_H_

namespace CJCU
{

class Record
{
	private:
		unsigned int data;

	public:
		Record();
		virtual ~Record();

		int getDepth();
		unsigned int getData();
		int** getBoard();
};

} /* namespace CJCU */

#endif /* RECORD_H_ */
