#!/usr/bin/python3

# AmpliPi Home Audio
# Copyright (C) 2021 MicroNova LLC
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

"""AmpliPi Webapp Init

This initializes the webapplication found in app.py.
"""

import os
import amplipi.app

mock_ctrl = os.environ.get('MOCK_CTRL', 'False').lower() == 'true'
mock_streams = os.environ.get('MOCK_STREAMS', 'False').lower() == 'true'

application = amplipi.app.create_app(delay_saves=True, mock_ctrl=mock_ctrl, mock_streams=mock_streams)
