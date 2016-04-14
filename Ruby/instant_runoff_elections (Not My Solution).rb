#Instant Runoff Voting
# http://www.codewars.com/kata/52996b5c99fdcb5f20000004/train/ruby
# DISCLAIMER: These two solutions are NOT mine. However, they have an aesthetic that I recognize as superior to my own and aspire towards.

# http://www.codewars.com/kata/reviews/5299f841b5570d9a9700035d/groups/54359958f0c10dec9b00030e

class IRV
  def initialize(votes)
    @voters = []
    @candidates = []
    @candidates_per_ballot = 0
    @rejected_candidates = []
    votes.each(&method(:add_voter))
  end

  def winner
    until (winning_candidate = majority_candidate) || !remaining_candidates?
      reject_candidates(*bottom_candidates)
    end
    winning_candidate
  end


  protected


  def majority_candidate
    majority_min = (@voters.count / 2.0).ceil
    candidate_totals.each do |candidate, total|
      return candidate if total >= majority_min
    end && nil
  end

  def bottom_candidates
    bottom = []
    min_votes = candidate_totals.values.min
    candidate_totals.each do |candidate, total|
      bottom << candidate if total == min_votes
    end
    bottom
  end

  def candidate_totals
    @candidate_totals ||= begin
      totals = @voters.map { |voter| voter.top_candidate }
      totals = totals.reduce({}) do |hash, candidate|
        hash[candidate] = hash[candidate].to_i + 1
        hash
      end
      blank_remaining_candidate_totals.merge(totals)
    end
  end

  def blank_remaining_candidate_totals
    @candidates.reduce({}) do |hash, candidate|
      hash[candidate] = 0 unless @rejected_candidates.include?(candidate)
      hash
    end
  end

  def remaining_candidates?
    @rejected_candidates.count < @candidates_per_ballot
  end

  def reject_candidates(*candidates)
    @voters.each { |voter| voter.reject_candidates(*candidates) }
    @candidate_totals = nil
    @rejected_candidates += candidates
  end

  def add_voter(votes)
    candidates_count = votes.count
    @candidates_per_ballot = candidates_count if candidates_count > @candidates_per_ballot
    @candidates = @candidates | votes
    @voters.push(Voter.new(votes))
  end
end

class Voter
  def initialize(votes)
    @votes = votes
  end

  def top_candidate
    @votes.first
  end

  def reject_candidates(*candidates)
    candidates.each { |candidate| @votes.delete(candidate) }
  end
end

def runoff (votes)
  IRV.new(votes).winner
end

# http://www.codewars.com/kata/reviews/5299f841b5570d9a9700035d/groups/52a7532cd3c7613dbc00089f

def runoff(ballots)
  Election.new(ballots).winner
end

class Election
  attr_accessor :ballots
  def initialize(ballots)
    @winner = nil
    @ballots = ballots.map { |ballot| Ballot.new(ballot) }
  end
  
  def round
    if win_threshold_cleared?
      forerunner
    else
      @ballots.each do |ballot|
        losers.each do |loser|
          ballot.cull(loser)
        end
      end
      round
    end
  end

  def winner
    @winner ||= round
  end
  
  def tally
    @ballots.map(&:current).inject(Hash.new(0)) { |h,v| h[v]+=1 ; h }
  end
  
  def forerunner
    tally.max_by{ |k, v| v }.first
  end
  
  def losers 
    tally.select{ |k, v| v == tally.min_by { |k, v| v }.last }.map(&:first)
  end
  
  def win_threshold_cleared?
    tally.max_by{ |k, v| v }.last >= (@ballots.size / 2).floor + 1
  end
end

class Ballot
  def initialize(selections)
    @selections = selections
  end
  
  def cull(loser)
    @selections.delete(loser)
  end
  
  def current
    @selections.first
  end
end