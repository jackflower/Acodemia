//acodemia.pl

#include "Physical.h"
namespace acodemia
{
	namespace physical
	{
		Physical::Physical()
		:
			m_displayable(),
			m_ready_for_destruction(false),
			m_use_displayable(false),
			m_speed(),
			m_position(),
			m_rotation(),
			m_origin(),
			m_scale(1, 1)
		{
		}

		Physical::~Physical()
		{
		}

	}//namespace physical
}//namespace acodemia