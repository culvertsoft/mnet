#pragma once

#include <se/culvertsoft/mnet/NodeAnnouncement.h>

namespace mnet {

	class Route {
		typedef se::culvertsoft::mnet::NodeAnnouncement NodeAnnouncement;

	public:
		Route() {

		}

		Route(const NodeAnnouncement& details) :
			m_details(details) {
		}

		const NodeAnnouncement& details() const {
			return m_details;
		}

		const std::string& name() const {
			return m_details.getName();
		}

		const std::vector<std::string>& tags() const {
			return m_details.getTags();
		}

	private:
		NodeAnnouncement m_details;

	};

}