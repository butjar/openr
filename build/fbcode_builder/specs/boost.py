#!/usr/bin/env python
# Copyright (c) Facebook, Inc. and its affiliates.
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals


def fbcode_builder_spec(builder):
    return {
        'steps': [
            builder.boost_download_build_install(),
        ],
    }
