#!/bin/bash

: <<'EOF'
bin/dettrace --prng-seed 1000 --epoch 2020-01-01,10:00:00 --clock-step 1000000 ./guess.bash
# You might have to press Return, Control+D after each answer.
EOF

for _ in $(seq 5); do
  n="$((RANDOM % 8 + 2))"
  printf "How many elephants are there? "
  printf "🐘%.s" $(seq $n)
  echo
  read -r r
  echo "You guessed ${r:-0} elephants."
  if test "${r:-0}" -eq "$n"; then
    echo "Correct! You have $((p += 1)) point(s)!"
  else
    echo "Wrong! There are $n elephants!"
  fi
  echo "You needed $SECONDS seconds in total."
  echo
done
