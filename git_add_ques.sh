#!/bin/env bash

question_name=$1
git add . &&
git commit -m "Added question: $question_name" &&
git push
