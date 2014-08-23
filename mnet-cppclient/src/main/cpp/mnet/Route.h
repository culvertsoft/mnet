#pragma once

#include <se/culvertsoft/mnet/NodeAnnouncement.h>

namespace mnet {

	class Route {
		typedef se::culvertsoft::mnet::NodeAnnouncement NodeAnnouncement;
		typedef se::culvertsoft::mnet::NodeUUID NodeUUID;

	public:
		Route() {

		}

		Route(const NodeAnnouncement& details) :
			m_details(details) {
		}

		const NodeAnnouncement& details() const {
			return m_details;
		}
		
		const NodeUUID& id() const {
			return m_details.getSenderId();
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
