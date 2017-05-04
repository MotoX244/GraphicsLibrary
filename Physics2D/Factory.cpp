#include "Factory.h"
//#include "ObjectPair/Line_Line.h"
//#include "ObjectPair/Line_Circle.h"
//#include "ObjectPair/Line_Rectangle.h"
//#include "ObjectPair/Line_AxisAlignedLine.h"
//#include "ObjectPair/Line_AxisAlignedRectangle.h"
#include "ObjectPair/Circle_Circle.h"
//#include "ObjectPair/Circle_Rectangle.h"
#include "ObjectPair/Circle_AxisAlignedLine.h"
//#include "ObjectPair/Circle_AxisAlignedRectangle.h"
//#include "ObjectPair/Rectangle_Rectangle.h"
//#include "ObjectPair/Rectangle_AxisAlignedLine.h"
//#include "ObjectPair/Rectangle_AxisAlignedRectangle.h"
//#include "ObjectPair/AxisAlignedLine_AxisAlignedLine.h"
//#include "ObjectPair/AxisAlignedLine_AxisAlignedRectangle.h"
#include "ObjectPair/AxisAlignedRectangle_AxisAlignedRectangle.h"

using namespace Physics2D;


ObjectPair* Factory::CreateObjectPair(Object& object1, Object& object2)
{
	switch ( object1.Type() )
	{
		//case ObjectType::Line:
		//	switch ( object2.Type() )
		//	{
		//		case ObjectType::Line:
		//			return new Line_Line(static_cast<Line&>(object1), static_cast<Line&>(object2));
		//		case ObjectType::Circle:
		//			return new Line_Circle(static_cast<Line&>(object1), static_cast<Circle&>(object2));
		//		case ObjectType::Rectangle:
		//			return new Line_Rectangle(static_cast<Line&>(object1), static_cast<Rectangle&>(object2));
		//		case ObjectType::AxisAlignedLine:
		//			return new Line_AxisAlignedLine(static_cast<Line&>(object1), static_cast<AxisAlignedLine&>(object2));
		//		case ObjectType::AxisAlignedRectangle:
		//			return new Line_AxisAlignedRectangle(static_cast<Line&>(object1), static_cast<AxisAlignedRectangle&>(object2));
		//	}
		//	break;

		case ObjectType::Circle:
			switch ( object2.Type() )
			{
		//		case ObjectType::Line:
		//			return new Line_Circle(static_cast<Line&>(object2), static_cast<Circle&>(object1));
				case ObjectType::Circle:
					return new Circle_Circle(reinterpret_cast<Circle&>(object1), reinterpret_cast<Circle&>(object2));
		//		case ObjectType::Rectangle:
		//			return new Circle_Rectangle(static_cast<Circle&>(object1), static_cast<Rectangle&>(object2));
				case ObjectType::AxisAlignedLine:
					return new Circle_AxisAlignedLine(reinterpret_cast<Circle&>(object1), reinterpret_cast<AxisAlignedLine&>(object2));
		//		case ObjectType::AxisAlignedRectangle:
		//			return new Circle_AxisAlignedRectangle(static_cast<Circle&>(object1), static_cast<AxisAlignedRectangle&>(object2));
			}

		//case ObjectType::Rectangle:
		//	switch ( object2.Type() )
		//	{
		//		case ObjectType::Line:
		//			return new Line_Rectangle(static_cast<Line&>(object2), static_cast<Rectangle&>(object1));
		//		case ObjectType::Circle:
		//			return new Circle_Rectangle(static_cast<Circle&>(object2), static_cast<Rectangle&>(object1));
		//		case ObjectType::Rectangle:
		//			return new Rectangle_Rectangle(static_cast<Rectangle&>(object1), static_cast<Rectangle&>(object2));
		//		case ObjectType::AxisAlignedLine:
		//			return new Rectangle_AxisAlignedLine(static_cast<Rectangle&>(object1), static_cast<AxisAlignedLine&>(object2));
		//		case ObjectType::AxisAlignedRectangle:
		//			return new Rectangle_AxisAlignedRectangle(static_cast<Rectangle&>(object1), static_cast<AxisAlignedRectangle&>(object2));
		//	}
		//	break;

		case ObjectType::AxisAlignedLine:
			switch ( object2.Type() )
			{
		//		case ObjectType::Line:
		//			return new Line_AxisAlignedLine(static_cast<Line&>(object2), static_cast<AxisAlignedLine&>(object1));
				case ObjectType::Circle:
					return new Circle_AxisAlignedLine(reinterpret_cast<Circle&>(object2), reinterpret_cast<AxisAlignedLine&>(object1));
		//		case ObjectType::Rectangle:
		//			return new Rectangle_AxisAlignedLine(static_cast<Rectangle&>(object2), static_cast<AxisAlignedLine&>(object1));
		//		case ObjectType::AxisAlignedLine:
		//			return new AxisAlignedLine_AxisAlignedLine(static_cast<AxisAlignedLine&>(object1), static_cast<AxisAlignedLine&>(object2));
		//		case ObjectType::AxisAlignedRectangle:
		//			return new AxisAlignedLine_AxisAlignedRectangle(static_cast<AxisAlignedLine&>(object1), static_cast<AxisAlignedRectangle&>(object2));
			}
			break;

		case ObjectType::AxisAlignedRectangle:
			switch ( object2.Type() )
			{
				//case ObjectType::Line:
				//	return new Line_AxisAlignedRectangle(static_cast<Line&>(object2), static_cast<AxisAlignedRectangle&>(object1));
				//case ObjectType::Circle:
				//	return new Circle_AxisAlignedRectangle(static_cast<Circle&>(object2), static_cast<AxisAlignedRectangle&>(object1));
				//case ObjectType::Rectangle:
				//	return new Rectangle_AxisAlignedRectangle(static_cast<Rectangle&>(object2), static_cast<AxisAlignedRectangle&>(object1));
				//case ObjectType::AxisAlignedLine:
				//	return new AxisAlignedLine_AxisAlignedRectangle(static_cast<AxisAlignedLine&>(object2), static_cast<AxisAlignedRectangle&>(object1));
				case ObjectType::AxisAlignedRectangle:
					return new AxisAlignedRectangle_AxisAlignedRectangle(reinterpret_cast<AxisAlignedRectangle&>(object1), reinterpret_cast<AxisAlignedRectangle&>(object2));
			}
			break;
	}

	return nullptr;
}
