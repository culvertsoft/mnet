#pragma once

#include <mgen/classes/MGenBase.h>

namespace mnet {

	template <typename Base>
	bool is_base(const mgen::MGenBase& unknown) {

		const std::vector<short>& baseIds = Base::_type_ids_16bit();
		const std::vector<short>& uknIds = unknown._typeIds16Bit();

		if (baseIds.size() > uknIds.size())
			return false;

		for (std::size_t i = 0; i < baseIds.size(); i++) {
			if (baseIds[i] != uknIds[i]) {
				return false;
			}
		}
		
		return true;
	}

}